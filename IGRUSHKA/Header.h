class APP {
public:
	class Entity {
	public:
		const int width = 30, height = 2560, spacing = 1280 / 5;
		int pos_x = 720, pos_y = 640;

		void Generate_pos_y(int prev_pos) {
			int is_positive = rand() % 2 + 1;
			pos_y = rand() % 100 + 1;
			if (is_positive == 1) {
				return;
			}
			else {
				pos_y = -pos_y;
				return;
			}
		}

		void tick_move() {
			pos_x -= 5;
		}

		void die() {

		}

	};
	bool IsAlive = true, IsGameRuns = false;
	const int ScreenHeight = 1280, ScreenWidth = 720, Whiskey_X = 260;
	int Whiskey_y = 640;
	int Whiskey_angle = 0;
	int acceleration = 0;
	int counter = 0;
	Entity entity1, entity2, entity3;
	int current_entity_last = 1;

	void Tick() {
		if (acceleration >= 0) {
			acceleration -= 2;
		}
		Whiskey_y += acceleration;
		counter++;
		if (counter == 300) {
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
		Whiskey_angle == acceleration * 30;
	}

	void Jump() {

		acceleration += 30;
		if (acceleration > 30) {
			acceleration = 30;
		}
		std::cout << acceleration;
	}

};