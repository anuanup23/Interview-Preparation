console.log("i love JS")
// getName();
// console.log(x);
// var x = 10;
// function getName(){
//     console.log("this is a logLine");
// }
// console.log(getName);
function x(y){
    console.log("x");
    y();
}
x(function y(){
    console.log('y');
})
