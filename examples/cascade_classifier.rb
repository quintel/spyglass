$LOAD_PATH.unshift('lib')
require 'spyglass/spyglass'

include Spyglass 

classifier  = CascadeClassifier.new("spec/fixtures/haarcascade_frontalface_default.xml")
window      = GUI::Window.new "Video"
cap         = VideoCapture.new 0
frame       = Image.new

loop do
  cap >> frame

  rects = classifier.detect(frame)
  rects.map { |r| frame.draw_rectangle(r) }

  window.show(frame)

  break if GUI::wait_key(10) > 0
end

