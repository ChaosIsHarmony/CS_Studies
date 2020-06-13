extends KinematicBody2D

const FRICTION = 200
const KNOCKBACK_FORCE = 100

const BatDestroyed = preload("res://Characters/BatDestroyed.tscn");

var knockback = Vector2.ZERO

onready var stats = $Stats

func _physics_process(delta):
	knockback = knockback.move_toward(Vector2.ZERO, FRICTION * delta)
	knockback = move_and_slide(knockback)


func _on_HurtBox_area_entered(area):
	stats.set_health(stats.health - area.damage)
	knockback = area.knockback_vector * KNOCKBACK_FORCE


func _on_Stats_death():
	var batDestroyed = BatDestroyed.instance()
	get_parent().add_child(batDestroyed)
	batDestroyed.global_position = global_position
	queue_free()
