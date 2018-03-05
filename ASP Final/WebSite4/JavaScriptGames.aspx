<%@ Page Language="C#" AutoEventWireup="true" CodeFile="JavaScriptGames.aspx.cs" Inherits="JavaScriptGames" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
<link href="Styles/Styles.css" rel="stylesheet" />
    <script src="Java/lib/easeljs-0.7.1.min.js"></script>
    <script src="Java/lib/tweenjs-0.5.1.min.js"></script>
    <script src="Java/breakout.js"></script>
    <style>
        canvas{
            background-color:black;
           
        }
            </style>
</head>
<body onload="init()">
    <div id="wrapper">
    <header><a href="Menu.aspx"><img src="Images/header2.jpg" height="119" width="700" alt="Company Logo" /></a></header>
    <form id="form1" runat="server">
    
    <nav></nav>
    <main> 
        <h4>Head back to the menu by clicking on the dragon</h4>
        <div class="cn">
        <canvas id="canvas" width="800" height="700"></canvas>
            </div>
        </main>
       
    <footer>Copyright &copy; Shadow Dragon Games 2014</footer>

    </form>
    </div>
</body>
</html>
