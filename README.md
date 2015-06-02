Dynamic-Economy-For-Games ( DEFG )
=================

A library that simulate an economical system for VideoGames , inspired and
based on the respective work of RedAdder and Nido , from this forum thread :
http://forums.vega-strike.org/viewtopic.php?f=21&t=13404

This version is designed for Windows system , with a working VC9 solution ( release mode only ).

*************************************************************************************************
HOW TO USE IT:
*************************************************************************************************

- Add the header file in your source :  #include "Economy.hpp"
- link defg.lib ( Location : lib/Release ) with your project.

*************************************************************************************************
Tutorial :
*************************************************************************************************

_Look in the Examples folder where you'll find some little projects that use that Lib .
They are just some little console programs that demonstrate how works the economy framework .

*************************************************************************************************
Experimental
*************************************************************************************************

( Included is an initial AI FSM based on http://www.ai-junkie.com/architecture/state_driven/tut_state1.html ,
that will serve to implement the Governor class , that will manage  bases and their associated factories . )



*************************************************************************************************
Configuration
*************************************************************************************************
About paths for the solution/project :

I use this $(HOME_VEGASTRIKE_MARKET) to define the root of the API for your convenience .
So you just have to define environment variable in windows to be able to compile and link.

Exemple : On my system , HOME_VEGASTRIKE_MARKET =  C:/YOUR_LOCAL_REPO/VegaMarket
Or you can manually set the header and lib locations .

Dependencies are :

_Boost 1_45 for windows ( NOT INCLUDED )
( I use the version from vegastrike folder from svn ... )
_xmlparse.lib ( INCLUDED )



