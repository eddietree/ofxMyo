ofxMyo
======

Wrapper for Thalmic Myo API (SDK Alpha 5) 

Currently only for Windows (Thalmic has not released the MacOSX API yet)


Installation
------------

To use ofxMyo, first you need to download and install [Open Frameworks](https://github.com/openframeworks/openFrameworks).

To get a copy of the repository you can download the source from [https://github.com/eddietree/ofxMyo](https://github.com/eddietree/ofxMyo) or, alternatively, you can use git clone:
<pre>
git clone git@github.com:eddietree/ofxMyo.git
</pre>

The addon should sit in `openFrameworks/addons/ofxMyo/`.


#### Windows - Visual Studio Setup

The project should compile properly if setup through OpenFramework's Project Generator. But it will fail to run unless you have copied the .dlls into the bin folder. 

To remedy this, simply copy the DLLs from of `openFrameworks/addons/ofxMyo/libs/myo-sdk/lib/bin` into the `openFrameworks/myApps/YOUR_PROJECT/bin` folder.
