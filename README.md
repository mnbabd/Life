# Life
Let life play out as you walk away from your screens.

This game of life comes with a graphical visualisation. The main purpose of this is to be used as a screensaver. 

Since screensavers are most commonly just binaries running on your machines. Making that binary open source is the most secure way to do this. Maybe not initially, but I would encourage you to report any vulnerabilities you spot (via issues).

# License
> [!CAUTION]
> This section is the expression of intent of the rights reserved and licenses used for the repository. Not a legal description of the details.

I have placed this repository under GNU General Public License.
Which for a general coder boils down to; if you take code from here, you have to make your repository open source as well. Most likely someone will spin up their own custom screensaver. This will ethically encourage them to make it open source and we can start a new FOSS Screensaver movement!

I reserve the right to use or redistribute my own code in this repo (modified or otherwise) under a different license elsewhere. All the individual files in this repo are under GNU General Public License unless redistributed to you by me (Muneeb) with explicit mention of change of license.

# Contribute
Feel free to create an issue on the repo
- Mainly for vulnerabilities, 
- Secondly, for efficiency improvements that do not impact readability or openness of this repo.
- Thirdly, general practices for bug reporting and improvements.

- (Fourthly, setting up a donate system to send money to appreciate my efforts. I'll create that ticket or set that up at some point. Add a donate section here when done.)

# Install dependencies

You will have most of these already installed.
```
sudo pacman -Syu base-devel glibc libc++ libc++abi linux-api-headers freeglut mesa mesa-utils glu
```

Optional:
```
sudo pacman -Syu glibc-debug
```
# Build
```
mkdir build
cd build
cmake ..
cmake --build .
```


# Story
It was one of the Covid-19 lockdowns here in NSW Australia. I was one of the fortunate people who could keep working from home while that was going on. That meant my work laptop was hooked to and sharing the monitors for my personal setup. A lot of the work I do needs a long-term 'leave it running' testing. Which means the power setting when plugged in do not auto sleep.

Enter corporate IT and 'look at all the things we do'-ness of companies pushing slideshow screensavers to employee machines. This never bothered me before because I normally leave my machine at work. But being in a small studio unit this seemed like sleeping/living next to a digital billboard. I am a really sensitive to bright lights specially in the peripheral vision, it causes migraines on occasion. After a couple of annoyed days and sleepless nights. On one of my sleepless, annoyed, hyperfocus coding spree I put together a Conway's Game of Life Screensaver. This dark background with slowly transitioning nice to look at visual was a great improvement on a sudden bright to dark transitions of corporate slideshows.

As part of it I learnt what interfaces and resources screensavers needed (this was windows with C# and some other native tools). Although, I wanted to share that screensaver with others. Sharing binaries around is something I don't like to do. This project was born out of this journey. Completely unrelated codebase, but the spirit of life and taking joy in little things lives on.
