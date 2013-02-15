ofxPosterize
============

###Intro

ofxPosterize is ad addon for [openFrameworks](http://openFrameworks.cc/), creative coding enviroment in C++.

ofxPosterize is usefull for apply [posterization](http://en.wikipedia.org/wiki/Posterization) effect to images.

So, from this:
![original](https://raw.github.com/nkint/ofxPosterize/master/example-extractColor/bin/data/webinterface/original.jpg)

to this:
![clustered](https://raw.github.com/nkint/ofxPosterize/master/example-extractColor/bin/data/webinterface/cluster.jpg)

###How it works
For theory guys: it involves process as image quantization, data clustering and segmentation.

For code guys: it uses [OpenCV library](http://opencv.org/), in particular the opencv2 c++ API.

For now it uses [kmeans](http://en.wikipedia.org/wiki/K-means_clustering) algorithm.

###Dependencies
It uses [ofxCv](https://github.com/kylemcdonald/ofxCv) addons and the precompiled opencv lib used in ofxOpenCV. Add them in the project.

