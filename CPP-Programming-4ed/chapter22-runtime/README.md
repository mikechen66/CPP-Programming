# stroustrup-ppp
Chapter 22 Run-Time Type Information

In general, a class is constructed from a lattice of base classes. Such a class lattice is often called a class hierarchy. We try to design classes so that users need not be unduly concerned about the way a class is composed out of other classes. In particular, the virtual call mechanism ensures that when we call a function f() on an object, the same function is called whichever class in the hierarchy pro- vided the declaration of f() used for the call and whichever class defined it. This chapter explains how to gain information about the total object given only the interface provided by a base class.


