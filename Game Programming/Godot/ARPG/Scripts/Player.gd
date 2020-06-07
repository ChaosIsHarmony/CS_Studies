extends KinematicBody2D

const MAX_SPEED = 100
const ACCELERATION = 500
const FRICTION = 500

var velocity = Vector2.ZERO

enum DIR { RIGHT, LEFT, UP, DOWN }
var curr_dir = DIR.DOWN

onready var animPlayer = $AnimationPlayer
onready var animTree = $AnimationTree
onready var animState = animTree.get("parameters/playback")

func _physics_process(delta):
	process_input(delta)
	process_movement(delta)


func process_input(delta):
	var input_vector = Vector2.ZERO
	input_vector.x = Input.get_action_strength("ui_right")-Input.get_action_strength("ui_left")
	input_vector.y = Input.get_action_strength("ui_down")-Input.get_action_strength("ui_up")
	input_vector = input_vector.normalized()
	
	if input_vector != Vector2.ZERO:
		animTree.set("parameters/idle/blend_position", input_vector)
		animTree.set("parameters/run/blend_position", input_vector)
		animState.travel("run")
		velocity = velocity.move_toward(input_vector * MAX_SPEED, ACCELERATION * delta)
	else:
		animState.travel("idle")
		velocity = velocity.move_toward(Vector2.ZERO, FRICTION * delta)

func process_movement(delta):
	velocity = move_and_slide(velocity)
