using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace TankFlow
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
       
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
  
            TankFlow f = new TankFlow(); //创建一个新窗体
            f.FormBorderStyle = FormBorderStyle.None; //设置窗体无边框
            f.ShowInTaskbar = false;
            f.BackColor = System.Drawing.Color.Black;
            f.TransparencyKey = f.BackColor; //让窗体透明 
            
            Application.Run(f);
        }

     
    }
}
