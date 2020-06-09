extends KinematicBody2D

const MAX_SPEED = 100
const ACCELERATION = 500
const FRICTION = 500

var velocity = Vector2.ZERO

enum DIR { RIGHT, LEFT, UP, DOWN }
var curr_dir = DIR.DOWN

enum STATE { MOVE, ROLL, ATTACK }
var state = STATE.MOVE

onready var animPlayer = $AnimationPlayer
onready var animTree = $AnimationTree
onready var animState = animTree.get("parameters/playback")

func _ready():
	animTree.active = true

func _physics_process(delta):
	match state:
		STATE.MOVE:	move_state(delta)
		STATE.ROLL: roll_state(delta)
		STATE.ATTACK: attack_state(delta)


func move_state(delta):
	var input_vector = Vector2.ZERO
	input_vector.x = Input.get_action_strength("ui_right")-Input.get_action_strength("ui_left")
	input_vector.y = Input.get_action_strength("ui_down")-Input.get_action_strength("ui_up")
	input_vector = input_vector.normalized()
	
	if input_vector != Vector2.ZERO:
		animTree.set("parameters/idle/blend_position", input_vector)
		animTree.set("parameters/run/blend_position", input_vector)
		animTree.set("parameters/attack/blend_position", input_vector)
		animState.travel("run")
		velocity = velocity.move_toward(input_vector * MAX_SPEED, ACCELERATION * delta)
	else:
		animState.travel("idle")
		velocity = velocity.move_toward(Vector2.ZERO, FRICTION * delta)
	
	velocity = move_and_slide(velocity)
	
	if Input.is_action_just_pressed("attack"):
		state = STATE.ATTACK


func attack_state(delta):
	velocity = Vector2.ZERO
	animState.travel("attack")


func attack_anim_over():
	state = STATE.MOVE


func roll_state(delta):
	pass
