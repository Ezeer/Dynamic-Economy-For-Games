Vegastrike_Market
=================

A library that simulate an economical system for Vegastrike
Based in the respective work of RedAdder and Nido , from this forum thread :
http://forums.vega-strike.org/viewtopic.php?f=21&t=13404

This version is designed for Windows system , with a working VC9 solution ( release mode only ).
Included an initial AI FSM based on http://www.ai-junkie.com/architecture/state_driven/tut_state1.html

About paths for the solution/project :

I use this $(HOME_VEGASTRIKE_MARKET) to define the root of the API .
So you must define environment variable in windows to be able to compile and link.
Exemple : On my system , HOME_VEGASTRIKE_MARKET= C:\Vegastrike_Market-master

Other dependency is :

_Boost 1_45 for windows .
You will find the source in your vegastrike folder from svn .\n
_xmlparse.lib ( now included in Vegastrike_Market/lib 


