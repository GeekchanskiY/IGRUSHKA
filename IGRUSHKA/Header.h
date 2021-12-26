class APP {
public:
	class Entity {
	public:
		const int width = 30, height = 2300, spacing = 650 / 5;
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
	const int ScreenHeight = 650, ScreenWidth = 480, Whiskey_X = 100;
	int Whiskey_y = 650;
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
		if (Whiskey_y < 0) {
			Whiskey_y = 5;
		}
		if (Whiskey_y >= 640) {
			Whiskey_y = 640;
		}
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

		acceleration += 10;
		if (acceleration > 10) {
			acceleration = 10;
		}
		std::cout << acceleration;
	}

};