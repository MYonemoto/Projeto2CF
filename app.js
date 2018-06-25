var config = {
    apiKey: "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    authDomain: "YOUR_PROJECT.firebaseapp.com",
    databaseURL: "https://YOUR_PROJECT.firebaseio.com",
    projectId: "YOUR_PROJECT",
    storageBucket: "YOUR_PROJECT.appspot.com",
    messagingSenderId: "xxxxxxxxxxx"
};
firebase.initializeApp(config);

var database = firebase.database();
var mov1ref = database.ref('mov1');
var ultra1ref = database.ref('ultra1');
var laser1ref = database.ref('laser1');

const mov1 = document.getElementById("mov1");
const ultra1 = document.getElementById("ultra1");
const laser1 = document.getElementById("laser1");

mov1ref.on("child_added", snap => {
    let data = snap.val();
    let $li = document.createElement("li");
    $li.innerHTML = data;
    mov1.append($li);
 });

 ultra1ref.on("child_added", snap => {
    let data2 = snap.val();
    let $li = document.createElement("li");
    $li.innerHTML = data2;
    ultra1.append($li);
 });

 laser1ref.on("child_added", snap => {
    let data3 = snap.val();
    let $li = document.createElement("li");
    $li.innerHTML = data3;
    laser1.append($li);
 });