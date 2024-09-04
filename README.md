# Fractol - 42 Project

## Overview

**Fractol** is a graphical application that generates and visualizes fractals, mathematical sets that exhibit intricate and infinitely complex patterns. This project is part of the 42 school curriculum and involves implementing algorithms to display fractals like the Mandelbrot set and Julia sets. The program is written in C and utilizes the MinilibX library for graphics rendering.

## Features

- Visualization of multiple fractals (Mandelbrot, Julia, etc.).
- Interactive zooming and panning.
- Dynamic color schemes for fractal visualization.
- Real-time parameter adjustments (for Julia sets).
- Keyboard and mouse controls for enhanced user interaction.

## Installation

1. Clone the repository:  
   ```bash
   git clone https://github.com/NzolaKiampava/fractol.git
   
2. Navigate to the project directory
     ```bash
   cd fractol
3. Compile the project:
    ```bash
    make

## IMAGES | MANDELBROT SET
![It is an image](https://github.com/NzolaKiampava/Fractol/blob/main/msndelbrot.png)

## IMAGE | JULIA SET
![It is an image](https://github.com/NzolaKiampava/Fractol/blob/main/julia.png)


## Usage

To run the program, use the following command:
   ```bash
      ./fractol [fractal_type] [optional parameters]
      ./fractol M
      ./fractol J -0.7 0.27015
      ./fractol J -0.7 0.27015
