extends KinematicBody2D

const MAX_SPEED = 100
const ROLL_SPEED = 125
const ACCELERATION = 500
const FRICTION = 500
const I_FRAMES = 0.5

var velocity = Vector2.ZERO

enum DIR { RIGHT, LEFT, UP, DOWN }
var curr_dir = DIR.DOWN

enum STATE { MOVE, ROLL, ATTACK }
var state = STATE.MOVE

var roll_vector = Vector2.ZERO

onready var animPlayer = $AnimationPlayer
onready var animTree = $AnimationTree
onready var animState = animTree.get("parameters/playback")
onready var swordHitBox = $SwordHitBoxPivot/SwordHitBox
onready var stats = PlayerStats
onready var hurtBox = $HurtBox

func _ready():
	stats.connect("death", self, "queue_free")
	animTree.active = true

func _physics_process(delta):
	match state:
		STATE.MOVE:
			move_state(delta)
		STATE.ROLL:
			roll_state(delta)
		STATE.ATTACK:
			attack_state(delta)


func move_state(delta):
	var input_vector = Vector2.ZERO
	input_vector.x = Input.get_action_strength("ui_right")-Input.get_action_strength("ui_left")
	input_vector.y = Input.get_action_strength("ui_down")-Input.get_action_strength("ui_up")
	input_vector = input_vector.normalized()
	
	if input_vector != Vector2.ZERO:
		roll_vector = input_vector
		swordHitBox.knockback_vector = roll_vector
		animTree.set("parameters/idle/blend_position", input_vector)
		animTree.set("parameters/run/blend_position", input_vector)
		animTree.set("parameters/attack/blend_position", input_vector)
		animTree.set("parameters/roll/blend_position", input_vector)
		animState.travel("run")
		velocity = velocity.move_toward(input_vector * MAX_SPEED, ACCELERATION * delta)
	else:
		animState.travel("idle")
		velocity = velocity.move_toward(Vector2.ZERO, FRICTION * delta)
		
	if Input.is_action_just_pressed("attack"):
		state = STATE.ATTACK
	if Input.is_action_just_pressed("roll"):
		hurtBox.set_invincible(true)
		hurtBox.start_i_frames(I_FRAMES)
		state = STATE.ROLL
	
	move()


func attack_state(delta):
	velocity = Vector2.ZERO
	animState.travel("attack")


func attack_anim_over():
	state = STATE.MOVE


func roll_state(delta):
	velocity = roll_vector * ROLL_SPEED
	animState.travel("roll")
	move()


func roll_anim_over():
	state = STATE.MOVE


func move():
	velocity = move_and_slide(velocity)


func _on_HurtBox_area_entered(area):
	if not hurtBox.get_invincible():
		stats.health -= area.damage
		hurtBox.start_i_frames(I_FRAMES)
		hurtBox.create_hit_effect()
