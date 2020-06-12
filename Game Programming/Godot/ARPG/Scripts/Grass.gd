extends Node2D

func create_effect():
	var GrassEffect = load("res://Levels/GrassEffect.tscn")
	var grass_effect = GrassEffect.instance()
	var world = get_tree().current_scene
	world.add_child(grass_effect)
	grass_effect.global_position = global_position
	


func _on_HurtBox_area_entered(area):
	create_effect()
	queue_free()
