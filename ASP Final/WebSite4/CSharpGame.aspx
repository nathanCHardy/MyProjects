<%@ Page Language="C#" AutoEventWireup="true" CodeFile="CSharpGame.aspx.cs" Inherits="CSharpGame" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
<link href="Styles/Styles.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            font-size: large;
            overflow: hidden;
            text-align: center;
            width: 100px;
            height: 30px;
        }
        .auto-style2 {
            font-size: small;
            overflow: hidden;
            text-align: right;
            width: 100px;
            height: 30px;
        }
    </style>
</head>
<body>
    <div id="wrapper">
     <header><a href="Menu.aspx"><img src="Images/header2.jpg" height="119"  alt="Company Logo" /></a></header>
    <form id="form1" runat="server">
    <nav></nav>
    <main>
     <h4>Head back to the menu by clicking on the dragon</h4>
    <div id="left">
            <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
            <asp:UpdatePanel ID="UpdatePanel1" runat="server">
                 <Triggers>
                    <asp:AsyncPostBackTrigger ControlID="Button1" EventName="Click" />
                      
                </Triggers>
                <ContentTemplate>  
    <asp:Image ID="Image1" CssClass="what" runat="server" ImageUrl="~/Images/fullbody.jpg"></asp:Image>
<asp:Button ID="Button1" runat="server" Text="Guess" OnClick="btnGuess_Click" Visible="False"></asp:Button>
</ContentTemplate>
            </asp:UpdatePanel>
      </div>
       <div id="right">
          <table border="0" class="stuff">
              
              <tr>
                  <td colspan="9" class="trows">Incorrect Guesses</td> 
                 
              </tr>
              <tr>
                  <td colspan="9" class="trows">
                  <asp:Label ID="WL1" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  <asp:Label ID="WL2" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  <asp:Label ID="WL3" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  <asp:Label ID="WL4" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  <asp:Label ID="WL5" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  <asp:Label ID="WL6" CssClass="wrong" runat="server" Text="_"></asp:Label>
                  </td>
                  
              </tr>
              <tr>
             <td colspan="9" class="trows"></td>
              </tr>
              <tr>
                  <td colspan="9" class="trows"><br /> <br /><br /><br /><br /><br /><br /><br /></td>
              </tr>
              
              <tr>
                  <td colspan="9" class="trows"><asp:Label ID="Label7" runat="server" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl1" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl2" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label> 
                      <asp:Label ID="lbl3" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl4" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl5" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl6" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl7" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl8" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      <asp:Label ID="lbl9" runat="server" CssClass="wrong" Text="_" Visible="False"></asp:Label>
                      </td>
              </tr>
              <tr>
                  <td class="trows"> <asp:Button ID="btnNewGame" runat="server" Text="New Game" OnClick="btnNewGame_Click" CausesValidation="False" UseSubmitBehavior="False"></asp:Button></td>
                  <td class="trows"></td>
                  <td class="trows"><asp:Button ID="btnGuess" runat="server" Text="Guess" OnClick="btnGuess_Click" CausesValidation="False" Enabled="False" UseSubmitBehavior="False"></asp:Button> </td>
              </tr>
              <tr>
                  <td class="trows"></td>
                  <td class="arows"><asp:Label ID="Label2" runat="server" Text="Enter a letter here ->"></asp:Label></td>
                  <td class="trows"><asp:TextBox ID="txtLetter" MaxLength="1"  runat="server" Width="31px"></asp:TextBox></td>
              </tr>
              <tr>
                  <td colspan="9" class="trows"> <asp:Label ID="Label1" runat="server" Text=""></asp:Label></td>
              </tr>
          </table>
           </div>
        
        </main>
       
    <footer>Copyright &copy; Shadow Dragon Games 2014</footer>

    </form>
    </div>
   
</body>
</html>
