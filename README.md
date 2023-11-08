## What is Adjusteer

Adjusteer is a simple arduino movement motivator.
Attached to a standing desk will it beep afer the configured amount of time of no vertical desk movement.

## Installation

- First, you need to get all components for this project.
    - Arduino (tested with Nano, Uno and Mega, but all major boards should work)
    - HC-SR04 (The distance sensor for arduino)
    - BEEPER (I have a no-name 3pin beeper)
- Wire up everything (The sketch tells you what pins to use)
- Upload the sketch
- attach to desk
- attach to power
- done.

## Usage

You dont have to do anything.
The arduino (your adjusteer) will remind you, that you should switch positions
It recognizes, that your desk moves and reset its internal timer
If you want it to stop beeping, just reset the arduino. (Pushbutton on all major arduino-dev-boards, OR cover the distance sensor with your hand. Adjusteer will think, that the table moved. No one will get hurt)

## Development

Feel free to tiker with the code! Its quite simple as of now.
This works ofc with the Arduino IDE, but there is also an upload script for arduino-cli users in the repo.

## Any questiones?

Feel free to open issues / PRs!

## Notes

This is far from done
Be assured that development on this continues, as i use this myself
