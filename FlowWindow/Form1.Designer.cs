namespace FlowWindow
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.minDamage = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.maxDamage = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.baoDamage = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.baoDamages = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.calculate = new System.Windows.Forms.Button();
            this.result = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.result1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // minDamage
            // 
            this.minDamage.Location = new System.Drawing.Point(75, 14);
            this.minDamage.Name = "minDamage";
            this.minDamage.Size = new System.Drawing.Size(66, 21);
            this.minDamage.TabIndex = 0;
            this.minDamage.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "最小伤害";
            // 
            // maxDamage
            // 
            this.maxDamage.Location = new System.Drawing.Point(75, 45);
            this.maxDamage.Name = "maxDamage";
            this.maxDamage.Size = new System.Drawing.Size(66, 21);
            this.maxDamage.TabIndex = 1;
            this.maxDamage.Text = "0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "最大伤害";
            // 
            // baoDamage
            // 
            this.baoDamage.Location = new System.Drawing.Point(75, 72);
            this.baoDamage.Name = "baoDamage";
            this.baoDamage.Size = new System.Drawing.Size(46, 21);
            this.baoDamage.TabIndex = 2;
            this.baoDamage.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 75);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 12);
            this.label3.TabIndex = 1;
            this.label3.Text = "暴击率";
            this.label3.Click += new System.EventHandler(this.Label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(123, 76);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(11, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "%";
            this.label4.Click += new System.EventHandler(this.Label3_Click);
            // 
            // baoDamages
            // 
            this.baoDamages.Location = new System.Drawing.Point(75, 99);
            this.baoDamages.Name = "baoDamages";
            this.baoDamages.Size = new System.Drawing.Size(46, 21);
            this.baoDamages.TabIndex = 3;
            this.baoDamages.Text = "150";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 102);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 1;
            this.label5.Text = "暴击伤害";
            // 
            // calculate
            // 
            this.calculate.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
            this.calculate.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.calculate.ForeColor = System.Drawing.Color.White;
            this.calculate.Location = new System.Drawing.Point(159, 14);
            this.calculate.Margin = new System.Windows.Forms.Padding(0);
            this.calculate.Name = "calculate";
            this.calculate.Size = new System.Drawing.Size(113, 106);
            this.calculate.TabIndex = 5;
            this.calculate.Text = "计算平均伤害";
            this.calculate.UseVisualStyleBackColor = false;
            this.calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // result
            // 
            this.result.AutoSize = true;
            this.result.Font = new System.Drawing.Font("微软雅黑", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.result.ForeColor = System.Drawing.Color.Red;
            this.result.Location = new System.Drawing.Point(92, 133);
            this.result.MaximumSize = new System.Drawing.Size(200, 0);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(29, 31);
            this.result.TabIndex = 3;
            this.result.Text = "0";
            this.result.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(123, 102);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(11, 12);
            this.label6.TabIndex = 1;
            this.label6.Text = "%";
            this.label6.Click += new System.EventHandler(this.Label3_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(23, 143);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 1;
            this.label7.Text = "平均伤害";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(23, 180);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(53, 12);
            this.label8.TabIndex = 1;
            this.label8.Text = "伤害增益";
            // 
            // result1
            // 
            this.result1.AutoSize = true;
            this.result1.Font = new System.Drawing.Font("微软雅黑", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.result1.ForeColor = System.Drawing.Color.Red;
            this.result1.Location = new System.Drawing.Point(92, 170);
            this.result1.MaximumSize = new System.Drawing.Size(200, 0);
            this.result1.Name = "result1";
            this.result1.Size = new System.Drawing.Size(29, 31);
            this.result1.TabIndex = 3;
            this.result1.Text = "0";
            this.result1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 213);
            this.Controls.Add(this.result1);
            this.Controls.Add(this.result);
            this.Controls.Add(this.calculate);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.baoDamage);
            this.Controls.Add(this.baoDamages);
            this.Controls.Add(this.maxDamage);
            this.Controls.Add(this.minDamage);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Opacity = 0.9D;
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "伤害计算器";
            this.TopMost = true;
            this.TransparencyKey = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox minDamage;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox maxDamage;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox baoDamage;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox baoDamages;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button calculate;
        private System.Windows.Forms.Label result;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label result1;
    }
}

