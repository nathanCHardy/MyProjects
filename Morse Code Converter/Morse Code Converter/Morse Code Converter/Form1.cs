using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Morse_Code_Converter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string[] MorseCode = new string[40] { " ", " --..--" , ".-.-.-" , "..--.." , "-----", ".----",
            "..---", "...--", "....-"," .....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-."," -..",
        ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string morseTranslation = "";
        char[] alphaNumeric = new char[] { ' ', ',', '.', '?', '0', '1','2', '3', '4', '5', '6',
            '7', '8', '9','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        private void btnConvert_Click(object sender, EventArgs e)
        {
            morseTranslation = "";
            string userMessage = txtSentence.Text.ToLower();

            foreach (char val in userMessage)
            {
                for (int x = 0; x < alphaNumeric.Length - 1; x++)
                {
                    if (val == ' ')
                    {
                        morseTranslation += " ";
                        break;
                    }
                    else if (val == alphaNumeric[x])
                    {
                        morseTranslation += MorseCode[x];
                        break;
                    }
                }
            }
            lblMorse.Text = morseTranslation;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
