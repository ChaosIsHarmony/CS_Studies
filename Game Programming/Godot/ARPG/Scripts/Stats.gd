extends Node

export var max_health = 1
onready var health = max_health setget set_health

signal death

func set_health(value):
	health = value
	if health <= 0:
		emit_signal("death")
