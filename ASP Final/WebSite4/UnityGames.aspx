<%@ Page Language="C#" AutoEventWireup="true" CodeFile="UnityGames.aspx.cs" Inherits="UnityGames" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
<link href="Styles/Styles.css" rel="stylesheet" />
    <script type='text/javascript' src='Unity/jquery.min.js'></script>
		<script type="text/javascript">

    var unityObjectUrl = "Unity/UnityObject2.js";
    if (document.location.protocol == 'https:')
        unityObjectUrl = unityObjectUrl.replace("http://", "https://ssl-");
    document.write('<script type="text\/javascript" src="' + unityObjectUrl + '"><\/script>');
   
		</script>
		<script type="text/javascript">
		<!--
    var config = {
        width: 960, 
        height: 600,
        params: { enableDebugging:"0" }
				
    };
    var u = new UnityObject2(config);

    jQuery(function() {

        var $missingScreen = jQuery("#unityPlayer").find(".missing");
        var $brokenScreen = jQuery("#unityPlayer").find(".broken");
        $missingScreen.hide();
        $brokenScreen.hide();
				
        u.observeProgress(function (progress) {
            switch(progress.pluginStatus) {
                case "broken":
                    $brokenScreen.find("a").click(function (e) {
                        e.stopPropagation();
                        e.preventDefault();
                        u.installPlugin();
                        return false;
                    });
                    $brokenScreen.show();
                    break;
                case "missing":
                    $missingScreen.find("a").click(function (e) {
                        e.stopPropagation();
                        e.preventDefault();
                        u.installPlugin();
                        return false;
                    });
                    $missingScreen.show();
                    break;
                case "installed":
                    $missingScreen.remove();
                    break;
                case "first":
                    break;
            }
        });
        u.initPlugin(jQuery("#unityPlayer")[0], "Unity/Ugame.unity3d");
    });
		</script>
</head>
<body>
    <div id="wrapper">
    <header><a href="Menu.aspx"><img src="Images/header2.jpg" height="119" width="700" alt="Company Logo" /></a></header>
    <form id="form1" runat="server">
    
    <nav></nav>
    <main> 
        <h4>Head back to the menu by clicking on the dragon</h4>
        <div class="cn">
        <div class="content">
			<div id="unityPlayer">
				<div class="missing">
					<a href="http://unity3d.com/webplayer/" title="Unity Web Player. Install now!">
						<img alt="Unity Web Player. Install now!" src="http://webplayer.unity3d.com/installation/getunity.png" width="193" height="63" />
					</a>
				</div>
				<div class="broken">
					<a href="http://unity3d.com/webplayer/" title="Unity Web Player. Install now! Restart your browser after install.">
						<img alt="Unity Web Player. Install now! Restart your browser after install." src="http://webplayer.unity3d.com/installation/getunityrestart.png" width="193" height="63" />
					</a>
				</div>
			</div>
		</div>
            </div>
        </main>
    <footer>Copyright &copy; Shadow Dragon Games 2014</footer>
    </form>
    </div>
</body>
    
</html>
