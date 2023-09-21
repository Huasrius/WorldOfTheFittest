#version 330 core

uniform vec4 ourColor;

out vec4 FragOutput; // Output color

void main()
{
    FragOutput = ourColor; // Output the color received from the vertex shader
}