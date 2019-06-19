
// predefined callback
a("saber-hyw",b);

// custom callback
a("saber-hyw",function(s) {
    console.log( s + ", how are you?");
});

function a(s, callback) {
    callback(s);
}

function b(s) {
    console.log(s + "!!!");
}
