class APP {
public:
	class Entity {
	public:
		const int width = 120, height = 2300, spacing = 650 / 5;
		int pos_x = 1400, pos_y = -325;

		void Generate_pos_y(int prev_pos) {
			int randoM_lengt = rand() % 200 + 1;
			int is_positive = rand() % 2 + 1;
			pos_y = rand() % 100 + 1;
			if (is_positive == 1) {
				if (pos_y + randoM_lengt <= -125) {
					pos_y = prev_pos + randoM_lengt;
				}
				else {
					pos_y = prev_pos - randoM_lengt;
				}
			}
			else {
				if (pos_y + randoM_lengt >= -700) {
					pos_y = prev_pos - randoM_lengt;
				}
				else {
					pos_y = prev_pos - randoM_lengt;
				}
			}
		}

		void tick_move() {
			pos_x -= 5;
		}
		// refreshes pos x and generates new pos y
		void die() {
			pos_x = 1400;
		}

	};
	bool IsAlive = true, IsGameRuns = false;
	const int ScreenHeight = 650, ScreenWidth = 1200, Whiskey_X = 100;
	int Whiskey_y = 325;
	int Whiskey_angle = 0;
	int acceleration = 0;
	int counter = 0;
	Entity entity1, entity2, entity3;
	int current_entity_last = 1;

	void Tick() {
		if (acceleration >= 0) {
			acceleration -= 2;
		}
		Whiskey_y -= acceleration;
		if (Whiskey_y < 5) {
			Whiskey_y = 5;
		}
		if (Whiskey_y >= 635) {
			Whiskey_y = 635;
		}
		change_angle();
		entity1.tick_move();
		entity2.tick_move();
		entity3.tick_move();
		counter++;
		if (counter == 360) {
			switch (current_entity_last)
			{
			default:
				break;
			case 1:
				entity1.die();
				break;
			case 2:
				entity2.die();
				break;
			case 3:
				entity3.die();
				break;
			}
			counter = 0;

		}
	}

	void change_angle() {
		Whiskey_angle = -acceleration * 5;

	}

	void Jump() {

		acceleration += 10;
		if (acceleration > 10) {
			acceleration = 10;
		}
		std::cout << acceleration;
	}
	void INIT_ENTITIES() {
		entity1.Generate_pos_y(-325);
	}

};