class APP {
public:
	
	class Entity {
	public:
		const int width = 120, height = 2300, spacing = 650 / 5;
		int pos_x = 1400, pos_y = -325;
		void start_pos(int set_pos_x) {
			pos_x = set_pos_x;
		}
		void Generate_pos_y(int prev_pos) {
			int randoM_lengt = rand() % 400 + 1;
			pos_y = -100 - randoM_lengt;
		}

		void tick_move(int Whiskey_y) {
			pos_x -= 5;
			if (pos_x >= 100 && pos_x <= 280) {
				std::cout << "I CAN KILL WOAHAHAHAH \n";
				if (Whiskey_y >= pos_y + 100 || Whiskey_y <= pos_y - 100) {
					std::cout << "I KILL \n";
				}
			}
			if (pos_x <= -200) {
				die();
				Generate_pos_y(pos_y);
			}
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
		if (acceleration > 0) {
			acceleration -= 10;
		}
		if (acceleration <= 20) {
			acceleration = -15;
			std::cout << "IM FALLING AAAAAAA";
		}
		Whiskey_y -= acceleration;
		if (Whiskey_y < 5) {
			Whiskey_y = 5;
		}
		if (Whiskey_y >= 635) {
			Whiskey_y = 635;
		}
		change_angle();
		entity1.tick_move(Whiskey_y);
		entity2.tick_move(Whiskey_y);
		entity3.tick_move(Whiskey_y);
		
	}
	void create_entities() {
		entity1.start_pos(1400);
		entity2.start_pos(1900);
		entity3.start_pos(2400);
	}
	void change_angle() {
		Whiskey_angle = -acceleration;

	}

	void Jump() {

		acceleration += 60;
		if (acceleration > 60) {
			acceleration = 60;
		}
	}
	void INIT_ENTITIES() {
		entity1.Generate_pos_y(-325);
	}

};