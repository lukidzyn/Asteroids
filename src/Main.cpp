#include "Platform/Platform.hpp"
#include <stdlib.h>
#include <time.h>

#define BLOCKS_NUM 600

int ScreenWidth = 1200;
const int ScreenHeight = 300;

float blocks[BLOCKS_NUM];
int bar_width;

sf::RenderWindow window;
sf::Event event;

int waitForClose();
void RandBars();
void SwapBars(int id1, int id2);
void swap(float* xp, float* yp);
void SortBars(float arr[], int n);

int main()
{
	window.setVerticalSyncEnabled(true);
	// window.setFramerateLimit(30);

	while (ScreenWidth % BLOCKS_NUM) //	assure bars are on whole window width
	{
		ScreenWidth++;
	}
	bar_width = ScreenWidth / BLOCKS_NUM;

	window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Hello world");
	window.clear(sf::Color::Black);
	RandBars();
	window.waitEvent(event);
	SortBars(blocks, BLOCKS_NUM);
	waitForClose();
	return 0;
}

int waitForClose()
{
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;
}

void RandBars()
{
	srand(time(NULL));
	sf::RectangleShape bars[BLOCKS_NUM];

	for (int i = 0; i < BLOCKS_NUM; i++)
	{
		blocks[i] = rand() % ScreenHeight + 1;
		std::cout << blocks[i] << "\n";
		bars[i].setSize(sf::Vector2f(bar_width, blocks[i]));
		bars[i].setPosition(i * bar_width, ScreenHeight - blocks[i]);
		window.draw(bars[i]);
	}
	window.display();
}

void SwapBars(int id1, int id2)
{
	int local_id;

	for (int i = 0; i < 2; i++)
	{
		local_id = (i == 0) ? id1 : id2;

		// Blackout
		sf::RectangleShape bar(sf::Vector2f(bar_width, ScreenHeight));
		bar.setPosition(local_id * bar_width, 0.0f);
		bar.setFillColor(sf::Color::Black);
		window.draw(bar);

		// Fillout
		bar.setPosition(local_id * bar_width, ScreenHeight - blocks[local_id]);
		bar.setFillColor(sf::Color::White);
		window.draw(bar);
		window.display();
	}
}

void swap(float* xp, float* yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SortBars(float arr[], int n)
{
	int i, j, minIdx;
	for (i = 0; i < n; i++)
	{
		minIdx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIdx])
				minIdx = j;

		swap(&arr[minIdx], &arr[i]);
		SwapBars(minIdx, i);
		window.clear();
		sf::sleep(sf::milliseconds(10));
	}
}