#!/usr/bin/env bash

# For Planck
./util/qmk_install.sh
make git-submodule planck/rev6_drop:heymatthew:flash

# For Corne (CKRBD)
## Based on hints from reddit
## See https://www.reddit.com/r/MechanicalKeyboards/comments/8ct02i/macos_quick_start_guide_for_flashing_kbd75/?st=JKF0BDVY&sh=aca1db0b
#util/qmk_install.sh
#
#echo "first half..."
#qmk flash -kb crkbd/rev1 -km heymatthew
#
#echo "second half..."
#qmk flash -kb crkbd/rev1 -km heymatthew
