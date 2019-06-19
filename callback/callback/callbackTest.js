
function someEvent(x, y, callbackFunc) {
    console.log("this is callback function!");
    return callbackFunc(x, y);
}

function sumFuc(x, y)
{
    console.log("sum: x+y = " + x + y);
    return x + y;
}

function multilplicationFunc(x, y)
{
    console.log("multiplication: x*y = " + x * y);
    return x * y;
}

someEvent(17, 18, sumFuc);
someEvent(10, 2, multilplicationFunc);










