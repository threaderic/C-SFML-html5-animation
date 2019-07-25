#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/OpenGL.hpp>
#endif

#include "Ball3d.h"
#include "system_info/sysinfo.h"

#include <iostream>
#include <random>
#include <algorithm>


float fl = 250,
        vpX = 0,
        vpY = 0,
        top = -150,
        bottom = 150,
        left = -200,
        right = 200,
        front = -200,
        back = 200;

int numBalls = 500;
std::vector<Ball3d> balls;

void Move(Ball3d &ball) {
    ball.xPos += ball.vx;
    ball.yPos += ball.vy;
    ball.zPos += ball.vz;

    //check boundaries
    if (ball.xPos + ball.shape.getRadius() > right) {
        ball.xPos = right - ball.shape.getRadius();
        ball.vx *= -1;
    } else if (ball.xPos - ball.shape.getRadius() < left) {
        ball.xPos = left + ball.shape.getRadius();
        ball.vx *= -1;
    }
    if (ball.yPos + ball.shape.getRadius() > bottom) {
        ball.yPos = bottom - ball.shape.getRadius();
        ball.vy *= -1;
    } else if (ball.yPos - ball.shape.getRadius() < top) {
        ball.yPos = top + ball.shape.getRadius();
        ball.vy *= -1;
    }
    if (ball.zPos + ball.shape.getRadius() > back) {
        ball.zPos = back - ball.shape.getRadius();
        ball.vz *= -1;
    } else if (ball.zPos - ball.shape.getRadius() < front) {
        ball.zPos = front + ball.shape.getRadius();
        ball.vz *= -1;
    }

    if (ball.zPos > -fl) {
        float scale = fl / (fl + ball.zPos);
        ball.shape.setScale(sf::Vector2f(scale, scale));
        ball.SetX(vpX + ball.xPos * scale);
        ball.SetY(vpY + ball.yPos * scale);
        ball.visible = true;
    } else
        ball.visible = false;
}

void CheckCollision(Ball3d &ballA, int i) {
    for (int j = i + 1; j < numBalls; ++j) {
        Ball3d ballB = balls[j];
        float dx = ballA.xPos - ballB.xPos;
        float dy = ballA.yPos - ballB.yPos;
        float dz = ballA.zPos - ballB.zPos;

        float dist = std::sqrt(dx * dx + dy * dy + dz * dz);

        if (dist < ballA.shape.getRadius() + ballB.shape.getRadius()) {
            ballA.shape.setFillColor(sf::Color::Blue);
            ballB.shape.setFillColor(sf::Color::Blue);
        }
    }
}

bool zSort(const Ball3d &ballA, const Ball3d &ballB) {
    return ballB.zPos < ballA.zPos;
}



int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    // Request a 24-bits depth buffer when creating the window
        sf::ContextSettings contextSettings;
        contextSettings.depthBits = 24;
        contextSettings.stencilBits= 8;
        contextSettings.antialiasingLevel = 4;
        contextSettings.majorVersion = 3;
        contextSettings.minorVersion = 0;
        contextSettings.attributeFlags = false;
        contextSettings.sRgbCapable = true;

    sf::RenderWindow window(sf::VideoMode(1980, 1080), "Collision 3D", sf::Style::Default,
                            contextSettings);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    // Make the window the active window for OpenGL calls
        window.setActive(true);

        // Enable Z-buffer read and write
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);

        // Disable lighting
        glDisable(GL_LIGHTING);

     // Configure the viewport (the same size as the window)
        glViewport(0, 0, window.getSize().x/2, window.getSize().y/2);
        
        
          // Setup a perspective projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
        glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 10.f);
        
        
        std::vector<CPUData> entries1;
	std::vector<CPUData> entries2;

	// snapshot 1
	ReadStatsCPU(entries1);

	// 100ms pause
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	// snapshot 2
	ReadStatsCPU(entries2);

	// print output
	PrintStats(entries1, entries2);

        
    std::mt19937 m(time(NULL));
    std::uniform_real_distribution<float> t(0.0f, 1.0f);
    vpX = window.getSize().x / 2.0f;
    vpY = window.getSize().y / 2.0f;

    for (int i = 0; i < numBalls; ++i) {
        balls.emplace_back(Ball3d(0, 0, 0, t(m)*10+5, sf::Color::Red));
        balls[i].xPos = t(m) * 400 - 200;
        balls[i].yPos = t(m) * 300 - 150;
        balls[i].zPos = t(m) * 400 - 200;
        balls[i].vx = t(m) * 5 - 1;
        balls[i].vy = t(m) * 5 - 1;
        balls[i].vz = t(m) * 5 - 1;
    }
    

    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            std::cout << "Escape!\n";
                            window.close();
                            break;
                        case sf::Keyboard::Space:
                            std::cout << "Space!\n";
                            window.setActive(true);
                            glViewport(0, 0, window.getSize().x, window.getSize().y);
                            break;
                        }
                case sf::Event::Resized:                {
                    std::cout << "resized!\n";
                    
                    // Make the window the active window for OpenGL calls
                    window.setActive(true);

                    glViewport(0, 0, window.getSize().x, window.getSize().y);
                    glMatrixMode(GL_PROJECTION);
                    glLoadIdentity();
                    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
                    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);


                }
            }
        }

        for (int i = 0; i < numBalls; ++i) {
            Move(balls[i]);
        }

        for (int i = 0; i < numBalls; ++i) {
            if (balls[i].shape.getFillColor() == sf::Color::Red) {
                //std::cout << "blue!!!"<< std::endl;
                CheckCollision(balls[i], i);
            }
        }

        std::sort(balls.begin(), balls.end(), zSort);

        window.clear(sf::Color::White);
        for (int i = 0; i < numBalls; ++i) {
            balls[i].Draw(window);
        }
        window.display();
    }

}
