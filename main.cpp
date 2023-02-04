#include <SFML/Graphics.hpp>
#include "settings.h"
#include "road.h"

using namespace sf;

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass;
	roadLayerInit(grass, Vector2f{ 0.f,0.f }, "grass.jpg");
	RoadLayer sand;
	roadLayerInit(sand, Vector2f{ 50.f,0.f }, "sand.png");
	RoadLayer road;
	roadLayerInit(road, Vector2f{ 100.f,0.f }, "road.jpg");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ��������� ���� 
		window.clear();
		window.draw(grass.sprite);
		window.draw(sand.sprite);
		window.draw(road.sprite);
		window.display();
	}

	return 0;
}