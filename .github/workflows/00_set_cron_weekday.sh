#! /usr/bin/env bash
## vim:set ts=4 sw=4 et:
set -e; set -o pipefail

# Copyright (C) Markus Franz Xaver Johannes Oberhumer

perl -i -pe $'s,(cron: \'.*) (\d)\'\],$1 3\'\],;' *.yml
#                                        ^-- HERE is the new weekday
