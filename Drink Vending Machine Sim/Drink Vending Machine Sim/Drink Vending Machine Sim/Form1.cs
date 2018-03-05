using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Drink_Vending_Machine_Sim
{
    struct Drinks
    {
        public string Name;
        public decimal Cost;
        public int Inventory;
    }
  
    public partial class Form1 : Form
    {
        Drinks[] Flavor = new Drinks[5];
        List<Label> sodaLabel = new List<Label>();
        int num;
        decimal SalesTotal = 0;
        public Form1()
        {
            InitializeComponent();
            SetInventory();
        }

        private void picCola_Click(object sender, EventArgs e)
        {
            sodaNumber(sender);
        }
        private void picRootBeer_Click(object sender, EventArgs e)
        {
            sodaNumber(sender);
        }
        private void picLemonLime_Click(object sender, EventArgs e)
        {
            sodaNumber(sender);
        }
        private void picGrape_Click(object sender, EventArgs e)
        {
            sodaNumber(sender);
        }
        private void picCream_Click(object sender, EventArgs e)
        {
            sodaNumber(sender);
        }
        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
      
        public void SetInventory()
        {
            lblCola.Text = "20";
            lblCream.Text = "20";
            lblGrape.Text = "20";
            lblLemonLime.Text = "20";
            lblRootBeer.Text = "20";

            for (int i = 0; i < Flavor.Length; i++)
            {
                Flavor[i].Inventory = 20;
            }
            sodaLabel.Add(lblCola);
            sodaLabel.Add(lblRootBeer);
            sodaLabel.Add(lblLemonLime);
            sodaLabel.Add(lblGrape);
            sodaLabel.Add(lblCream);
            Flavor[0].Cost = 1.00M;
            Flavor[0].Name = "Cola";
            Flavor[1].Cost = 1.00M;
            Flavor[1].Name = "Rootbeer";
            Flavor[2].Cost = 1.00M;
            Flavor[2].Name = "Lemon Lime";
            Flavor[3].Cost = 1.50M;
            Flavor[3].Name = "Grape";
            Flavor[4].Cost = 1.50M;
            Flavor[4].Name = "Cream Soda";
        }

      public void sodaNumber(object sender)
        {
            if (sender == picCola) num = 0;
            if (sender == picRootBeer) num = 1;
            if (sender == picLemonLime) num = 2;
            if (sender == picGrape) num = 3;
            if (sender == picCream) num = 4;
            if (Flavor[num].Inventory >= 1)
            {
                Flavor[num].Inventory -= 1;
                SalesTotal += Flavor[num].Cost;
                sodaLabel[num].Text = Flavor[num].Inventory.ToString();
                lblTotal.Text = SalesTotal.ToString("c");
            }
            if (Flavor[num].Inventory <= 0)
            {
                sodaLabel[num].Text = "Sold Out";
                MessageBox.Show($"Sold out of {Flavor[num].Name}, please select another soda");
            }
        }
    }
}
