;; -*- Mode: Lisp -*-
(declaim (optimize (speed 3)
                   (compilation-speed 0)
                   (safety 0)
                   (debug 0)))
(load "sysdef.lisp")
(load "compile-cmulisp.lisp")
(make::make :maxima :compile t)
(setq maxima::*maxima-directory* (namestring (truename "../")))
(load "init_max1")
(save-lisp "maxima_core")
