bouncing_ball.wasm: bouncing_ball.c
	clang --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--allow-undefined -Wl,--export=game_init -Wl,--export=game_frame -Wl,--export=game_over -o bouncing_ball.wasm bouncing_ball.c -DPLATFORMWEB

bouncing_ball_native: bouncing_ball.c
	clang -o bouncing_ball bouncing_ball.c -L../include -lraylib -lm
