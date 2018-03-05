var sf = 100;
var images = new Array ("Image/Pic1.png", "Image/Pic2.png", "Image/Pic3.jpg", "Image/Pic4.png", "Image/Pic5.png");

function start() {
 StSlide = setInterval(function() {
var rand = Math.floor(Math.random() * 5),
 stuff = document.getElementById("pic1");
 if (rand === 0) {
 stuff.style.height = "200px";
 }
 else if (rand === 1) {
 stuff.style.height = "200px";
 }
 else if  (rand === 2) {
 stuff.style.height = "100px" 
 }
 else {
 stuff.style.height = "400px";
 }
stuff.src = images[rand]; 
}, 2000);
}
function stop() {
clearInterval(StSlide);
}
function easterEgg() {
alert("Forms are boring, colors are fun");
$(function() {
		var colors = ["#000000", "#FFFFFF", "#EEFFEE", "#CCEE00", "#FFCCFF", "#0011EE", "#FFCC00", "#CCFF11", "#FFEE11", "#EECCFF"];
		setInterval(function() {
		var num = Math.floor(Math.random() * colors.length);
		var stuff = colors[num];
		$("body").css('background', stuff);
		}, 300);
		});
} 
var Cform = document.getElementById("Cont");
Cform.addEventListener("submit", function(event){
var Name = document.getElementById("name").value,
phone = document.getElementById("phone").value,
email = document.getElementById("email").value,
com = document.getElementById("comment");
tomatch = /^\d{3}-\d{3}-\d{4}$/;
toemail = /[-0-9a-zA-Z.+_]+@[-0-9a-zA-Z.+_]+\.[a-zA-Z]{2,4}/;
event.preventDefault();
if (Name === "") {
alert("I don't know your name, so try putting it in first.");
}
		else if (!tomatch.test(phone)) {
		  alert("Invalid phone number entered. Valid format is xxx-xxx-xxxx.");
			}
else if  (!toemail.test(email)) {
alert("Not a valid e-mail");
}
else if (comment.value == "") {
alert("I need to know what you want, so I can get back to you");
}
else {
alert("Thank you for your interest!");
}
}, false);

function Fun() {
var s = document.querySelector("#about");
var t = document.querySelector("#about1");
var u = document.querySelector("#about2");
var w = document.querySelector("#about3");
var color = window.prompt("Pick a color name", "");
s.style.color = color;
t.style.color = color;
u.style.color = color;
w.style.color = color;
}

function dice() {
var images = new Array ("Image/Die1.BMP", "Image/Die2.BMP", "Image/Die3.BMP", "Image/Die4.BMP", "Image/Die5.BMP", "Image/Die6.BMP");
var rand1 = Math.floor(Math.random() * 6),
rand2 = Math.floor(Math.random() * 6),
rand3 = Math.floor(Math.random() * 6),
total = 100,
bank = 0,
stuff = 0,
D1 = document.getElementById("P1"),
D2 = document.getElementById("P2"),
D3 = document.getElementById("P3"),
bet = document.getElementById("bet"),
score = document.getElementById("score");
D1.src = images[rand1];
D2.src = images[rand2];
D3.src = images[rand3];


if (bet.value <= sf) {
if (rand1 ===  rand2  && rand3 === rand2){
bank = parseInt(bet.value);
if (Math.floor(bank) == bank && bank > 0) {
sf += bank * 2;
}
else{
alert("Enter a number bet");
}
}
else if (rand1 === 3 && rand2 === 4 && rand3 === 5){
bank = parseInt(bet.value);
if (Math.floor(bank) == bank && bank > 0) {
sf += bank * 100;
}
else{
alert("Enter a number bet");
}
}
else if (sf <= 0){
alert("sorry try again later");
}
else {
bank = parseInt(bet.value);
if (Math.floor(bank) == bank && bank > 0) {
sf -=bank;
}
else {
alert("Enter a number bet");
}
}
}
else {
alert("Not enough money");
}
score.innerHTML = sf;
bet.value = "";
bet.focus();
}


var my_no,count;
function load() {
window.defaultStatus="JavaScript Guess-a-Number Game";
document.game.help.value="Please set range of numbers and press the Start button.";
document.game.from.focus(); }
function rnd(scale) {
var dd=new Date();
return((Math.round(Math.abs(Math.sin(dd.getTime()))*8.71*scale)%scale)); }
function range() {
var to=1+1*document.game.to.value;
count=0;
my_no=rnd(to);
while(my_no<document.game.from.value) {
my_no=rnd(to); }
document.game.help.value="Please guess a number, enter it, and press Guess."; }
function guess() {
var no=document.game.number.value;
count++;
if (Math.floor(no) == no) {
if(no<my_no) document.game.help.value="My number is greater than "+no+".";
else if(no>my_no) document.game.help.value="My number is less than "+no+".";
else alert("It took you "+count+" attempt(s) to guess my number");
}
else { alert("Not a number");} }
