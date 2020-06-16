extends Camera2D

const ZOOM_IN_DELTA = 0.0125
const ZOOM_OUT_DELTA = 0.001

onready var player = get_node("../YSort/Player")

func _ready():
	player.connect("in_combat", self, "zoom_in")
	player.connect("not_in_combat", self, "zoom_out")


func zoom_in():
	if self.zoom.x > 0.8:
		self.zoom = Vector2(self.zoom.x-ZOOM_IN_DELTA, self.zoom.y-ZOOM_IN_DELTA)


func zoom_out():
	if self.zoom.x < 0.99:
		self.zoom = Vector2(self.zoom.x+ZOOM_OUT_DELTA, self.zoom.y+ZOOM_OUT_DELTA)
