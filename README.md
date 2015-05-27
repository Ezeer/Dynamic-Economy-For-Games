Vegastrike_Market
=================

A library that simulate an economical system for Vegastrike
Based in the respective work of RedAdder and Nido , from this forum thread :
http://forums.vega-strike.org/viewtopic.php?f=21&t=13404

This version is designed for Windows system , with a working VC9 solution ( release mode only ).
The project is a little console program that demonstrate how works the framework .

( Included is an initial AI FSM based on http://www.ai-junkie.com/architecture/state_driven/tut_state1.html ,
that will serve to implement the Governor class , that will manage  bases and their associated factories . )

My idea is to make that project API oriented , with static link (.lib) for get rid of the .cpp , and dll to plug
at vegastrike.exe 
( I know linux and Mac users won't like that , but there will be a source version too for them , to tweak thewindows
specific parts in portable code )

Any help is welcome , and i stay tuned with Nido that has his original version

**************************************

About paths for the solution/project :

I use this $(HOME_VEGASTRIKE_MARKET) to define the root of the API .
So you must define environment variable in windows to be able to compile and link.
Exemple : On my system , HOME_VEGASTRIKE_MARKET =  C:/YOUR_LOCAL_REPO/VegaMarket

Other dependencies are :

_Boost 1_45 for windows .
You will find the source in your vegastrike folder from svn .
_xmlparse.lib ( now included in Vegastrike_Market/lib 


