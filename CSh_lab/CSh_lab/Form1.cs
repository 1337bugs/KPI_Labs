using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSh_lab
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        int n;
        string testString;

        private void button1_Click(object sender, EventArgs e)
        {
            //    button1.Text = "Exit";
            //   button1.Click += new EventHandler(button1_Click);
            
            Random r = new Random();
            Random g = new Random();
            Random b = new Random();
            Color redColor = Color.FromArgb(r.Next(0, 256), g.Next(0, 256), b.Next(0, 256));
            this.button1.ForeColor = redColor;
                //   this.textBox1.Clear();
            n++;
            label3.Text = n.ToString();
            if (n>=10)
            {
                System.Environment.Exit(0);
            }
        }



        private void textBox1_TextChanged(object sender, EventArgs e)
        {

            testString = textBox1.Text;
            textBox1.KeyDown += new KeyEventHandler(textBox1_KeyDown);
            Random r = new Random();
            Random g = new Random();
            Random b = new Random();
            if (testString == "exit")
            {
                System.Environment.Exit(0);
                //   this.textBox1.Clear();
            }
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                testString = textBox1.Text;
                textBox1.Clear();
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {
            
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
