using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace TankFlow
{
    public partial class TankFlow : Form
    {
        const int WM_COPYDATA = 0x004A;
        const int EVENT = 30000;
        const int BATTLE_START = 36278;
        const int BATTLE_END = 36279;
        const int SPOTED = 36281;
        const int UNSPOTED = 36280;
        const string GameClass = "UnityWndClass";
        const string GameName = "Tank Battle";
        PCManager manager;
        volatile bool is_exit = false;
        Thread con;


        List<Damage> damage_list=new List<Damage>();
        public TankFlow()
        {
            InitializeComponent();
            initWindow();
            
            this.postimer.Stop();
            this.StartPosition = FormStartPosition.Manual;
            followPosition();
            manager = new PCManager(100);
            con= new Thread(() =>
            {
                Damage m = null;
                while (!is_exit&&m==null)
                {
                    m = (Damage)manager.GetProduct(1000);
                    if(m!=null)
                        Connector.add_damage(m);
                    else
                    {
                        Console.WriteLine("没有获取到产品");
                    }
                }
                Console.WriteLine("消费者线程退出");
            });//创建消费者线程将数据上传至数据库
            con.Start();
            //this.Location = new System.Drawing.Point((int)(0), (int)(0));
        }

        //初始化窗口数据
        private void initWindow()
        {
            label1.Text = "";
            label2.Text = "";
            label3.Text = "";
            label4.Text = "";
            label5.Text = "";
            label6.Text = "";
        }

        //添加字符串至窗口
        public void PushString(string s)
        {
            label6.Text = label5.Text;
            label5.Text = label4.Text;
            label4.Text = label3.Text;
            label3.Text = label2.Text;
            label2.Text = label1.Text;
            label1.Text = s;
        }

        //消息处理函数
        /**/
        protected override void DefWndProc(ref System.Windows.Forms.Message m)
        {
            switch (m.Msg)
             {
                 case WM_COPYDATA:
                    string s1=getCopyMessage(ref m);
                    Console.WriteLine("收到字符串：" + s1);
                    Damage dama = new Damage(s1);
                    string s2 = dama.parse();
                    damage_list.Add(dama);
                    if (!s2.Equals(""))
                    {
                        PushString(s2);
                    }
                    this.postimer.Start();
                    break;
                case EVENT:
                    OnHandleEvent((int)m.LParam);
                    break;
              
                default:
                     base.DefWndProc(ref m);
                    break;
             }
             
        }
        
        private void uploadData()
        {
           foreach(Damage m in damage_list)
            {
                if (m.valid)
                    manager.AddProductPlus(m);
            }
            damage_list.Clear();
        }

        private void OnHandleEvent(int flag)
        {
            switch (flag)
            {
                case BATTLE_START:
                    initWindow();
                    this.postimer.Start();
                    Console.WriteLine("战斗开始");
                    break;
                case BATTLE_END:
                    this.postimer.Stop();
                    this.Hide();
                    Console.WriteLine("战斗结束");
                    uploadData();
                    break;
                case SPOTED:
                    this.spot_state.Visible = true;
                    break;
                case UNSPOTED:
                    this.spot_state.Visible = false;
                    break;
                default:
                    Console.WriteLine(flag);
                    break;
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct COPYDATASTRUCT
        {
            public IntPtr dwData;
            public int cbData;
            public IntPtr lpData;
        }

        private void Button1_Click(object sender, EventArgs e)
        {

        }

        //获取传递过来的字符串
        private string getCopyMessage(ref System.Windows.Forms.Message m)
        {
            COPYDATASTRUCT mystr = new COPYDATASTRUCT();
            Type mytype = mystr.GetType();
            mystr = (COPYDATASTRUCT)m.GetLParam(mytype);
            int flag = (int)mystr.dwData;
            byte[] bt = new byte[mystr.cbData];
            Marshal.Copy(mystr.lpData, bt, 0, bt.Length);
            string m2 = System.Text.Encoding.Unicode.GetString(bt);
            Console.WriteLine(m2);
            return m2;
        }

        //定时器执行动作
        private void Postimer_Tick(object sender, EventArgs e)
        {
            followPosition();
        }

        //设置窗口跟随游戏窗口移动
        private void followPosition()
        {
            IntPtr hwnd = BaseAPI.FindWindow(GameClass, GameName);
            IntPtr forgeWindow = BaseAPI.GetForegroundWindow();
            if (hwnd != forgeWindow)
            {
                this.TopMost = false;
                this.Hide();
                return;
            }
            BaseAPI.RECT client;
            BaseAPI.GetWindowRect(hwnd, out client);
            
            this.Location = new System.Drawing.Point((int)(client.Left + 165), (int)(client.Bottom - 210));
            this.TopMost = true;
            this.Show();
        }

        private void TankFlow_FormClosed(object sender, FormClosedEventArgs e)
        {
            is_exit = true;
            con.Join();
        }
    }
}
