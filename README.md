# runtimechooser
Uses boost::mpl to generate all possible combinations of list elements at compile time and provides the possibility to select one of these combinations at run-time.

This code is used in the autotuner of cuLGT. For multiple compile-time sequences `A1, ..., An` a new sequence `B` is generated with N-dimensional elements built from all combinations of `A1, ..., An` elements.
Given `A1 = {1,2}` and `A2 = {X,Y}`, the new sequence will be `B={{1,X},{1,Y},{2,X},{2,Y}}`. This sequence can then be used to generate template functions based on `B`'s entires.

These can be used as input in an (run-time) iterator to run all combinations and choose the best one.

See the example files for its application.
