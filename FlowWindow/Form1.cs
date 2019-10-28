using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FlowWindow
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Label3_Click(object sender, EventArgs e)
        {

        }

        private void Calculate_Click(object sender, EventArgs e)
        {
            int min = System.Convert.ToInt32(this.minDamage.Text);
            int max = System.Convert.ToInt32(this.maxDamage.Text);
            double baolv = System.Convert.ToDouble(this.baoDamage.Text);
            int baos = System.Convert.ToInt32(this.baoDamages.Text);


            double ave2 = calculate_ave(min, max, baolv, baos);

            this.result.Text = ave2.ToString();

            
        }


        private double calculate_ave(int min,int max,double baolv,double baos)
        {
            float ave1 = (max + min) / 2f;
            double baosum = ave1 * baos / 100f * baolv;
            double comsum = ave1 * (100f - baolv);
            double ave2 = (baosum + comsum) / 100f;

            return ave2;
        }

    }
}
