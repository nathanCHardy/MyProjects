<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Password.aspx.cs" Inherits="Password" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Password Recovery</title>
     <link href="Styles/Styles.css" rel="stylesheet" />
</head>
<body>
    <div id="wrapper">
    <header><img src="Images/header2.jpg" height="119" width="700" alt="Company Logo" /></header>
    <form id="form1" runat="server">
    
    <nav></nav>
    <main> 
<asp:PasswordRecovery ID="PasswordRecovery1" runat="server" BackColor="#F7F7DE" BorderColor="#CCCC99" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="10pt">
    <TitleTextStyle BackColor="#6B696B" Font-Bold="True" ForeColor="#FFFFFF" />
    <MailDefinition From="Admin@dArcade.com"></MailDefinition>
        </asp:PasswordRecovery>
        </main>
       
    <footer>Copyright &copy; Shadow Dragon Games 2014</footer>

    </form>
    </div>
</body>
</html>
