


function a(callback) 
{
    console.log("this is parent`s function:a!");
    console.log("call function : callback");
    callback();
}

function b()
{
    console.log("callback function : b ");
}

function c() 
{
    console.log("callback function : c");
}

function start()
{
    a(b);
    a(c);
    b();
}

start();