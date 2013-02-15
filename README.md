ofxPosterize
============

###Intro

ofxPosterize is ad addon for [openFrameworks](http://openFrameworks.cc/), creative coding enviroment in C++.

ofxPosterize is usefull for apply [posterization](http://en.wikipedia.org/wiki/Posterization) effect to images.

So, from this:
![original](https://github.com/nkint/ofxPosterize/blob/master/example_extractColor/bin/data/lena.jpg)

to this:
![clustered](https://github.com/nkint/ofxPosterize/blob/master/example_extractColor/bin/data/clustered.jpg)

###How it works
For theory guys: it involves process as image quantization, data clustering and segmentation.

For code guys: it uses [OpenCV library](http://opencv.org/), in particular the opencv2 c++ API.

For now it uses [kmeans](http://en.wikipedia.org/wiki/K-means_clustering) algorithm.

###Dependencies
It uses [ofxCv](https://github.com/kylemcdonald/ofxCv) addons and the precompiled opencv lib used in ofxOpenCV. Add them in the project.

