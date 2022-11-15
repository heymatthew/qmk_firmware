#!/usr/bin/env bash

# See https://www.reddit.com/r/MechanicalKeyboards/comments/8ct02i/macos_quick_start_guide_for_flashing_kbd75
./util/qmk_install.sh
make git-submodule

case $1 in
    planck)
        # https://github.com/yanghu/qmk_firmware/tree/master/keyboards/planck
        echo "Please flip planck, hold reset, and plug in to flash..."
        # make planck/rev6_drop:default:flash
        make planck/rev6_drop:heymatthew:flash
        ;;

    corne)
        # FIXME explodes with errors
        # https://github.com/yanghu/qmk_firmware/tree/master/keyboards/crkbd
        echo "Please press reset on first half..."
        # make crkbd/rev1:heymatthew:build
        make crkbd/rev1:default:build

        echo "Please press reset on second half..."
        # make crkbd/rev1:heymatthew:build
        make crkbd/rev1:default:build
        ;;

    ploopy)
        # https://github.com/ploopyco/mouse/wiki/Appendix-D%3A-QMK-Firmware-Programming
        echo "Plug in mouse while holding 'back' button..."
        # make ploopyco/trackball:default:flash
        make ploopyco/trackball:heymatthew:flash
        ;;

    *)
        echo
        echo "Oh dear! Cowardly refusing to flash."
        echo "Support for planck, corne, or ploopy in \$1"
        exit 1
        ;;
esac
