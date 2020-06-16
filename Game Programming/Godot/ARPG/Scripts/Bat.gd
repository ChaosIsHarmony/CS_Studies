extends KinematicBody2D

const ACCELERATION = 300
const MAX_SPEED = 50
const FRICTION = 200
const KNOCKBACK_FORCE = 100

enum STATE {
	IDLE,
	WANDER,
	CHASE
}

var state = STATE.IDLE

const BatDestroyed = preload("res://Characters/BatDestroyed.tscn");

var velocity = Vector2.ZERO
var knockback = Vector2.ZERO

onready var sprite = $Body
onready var stats = $Stats
onready var detection_range = $DetectionRange
onready var hurtBox = $HurtBox
onready var softCollision = $SoftCollision

func _physics_process(delta):
	knockback = knockback.move_toward(Vector2.ZERO, FRICTION * delta)
	knockback = move_and_slide(knockback)
	
	match state:
		STATE.IDLE:
			velocity = velocity.move_toward(Vector2.ZERO, FRICTION * delta)
			seek_player()
		STATE.WANDER:
			state = STATE.IDLE
		STATE.CHASE:
			var player = detection_range.player
			if player != null:
				var direction = (player.global_position - global_position).normalized()
				velocity = velocity.move_toward(direction * MAX_SPEED, ACCELERATION * delta)
			else:
				state = STATE.WANDER
			sprite.flip_h = velocity.x < 0
	
	#prevents bats from overlapping
	velocity += softCollision.get_push_vector()
	
	velocity = move_and_slide(velocity)	


func seek_player():
	if detection_range.player_visible():
		state = STATE.CHASE


func _on_HurtBox_area_entered(area):
	stats.set_health(stats.health - area.damage)
	knockback = area.knockback_vector * KNOCKBACK_FORCE
	hurtBox.create_hit_effect()


func _on_Stats_death():
	var batDestroyed = BatDestroyed.instance()
	get_parent().add_child(batDestroyed)
	batDestroyed.global_position = global_position
	queue_free()
