<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Menu.aspx.cs" Inherits="Menu" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Menu</title>
<link href="Styles/Styles.css" rel="stylesheet" />
</head>
<body>
    <div id="wrapper">
    <header><img src="Images/header2.jpg" height="119" width="700" alt="Company Logo" /></header>
    <form id="form1" runat="server">
    
   
        <nav>
    <ul>
      <li><a href="CSharpGame.aspx">C# Games</a></li>
      <li><a href="JavaScriptGames.aspx">JavaScript Games</a></li>
      <li><a href="UnityGames.aspx">Unity 3D Games</a></li>
      <li><a href="How.aspx">How to </a></li>
	</ul>
            <hr />
    </nav>
    <main> 
       <p>Welcome to the Dragon Arcade. A place to play and learn all about games and development. 
           Each page has an example of a game written in a different language, or a combination there of.
           Explore each game and have fun, then try the how to page for helpful information.

  </p>
        <h3>Details</h3>
        <p><strong>C#</strong> is Microsoft language with great versatility and power. It can be used to create complex games for 
            PC and Microsoft X-Box consoles.
        </p>        
        <p><strong>JavaScript</strong> is a client side scripting language that brings fun and interesting effects to 
            the web. But you may be surprised to find creative people making games with it as well.
        </p>
        <p><strong>Unity</strong> is not a language but a tool. It is used to make games as well as 3d models.
            It includes the use of C# and JavaScript, as well as it's own scripting language.
        </p>
         </main>
       
        <footer>Copyright &copy; Shadow Dragon Games 2014</footer>
    </form>
    </div>
</body>
</html>