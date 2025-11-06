FILE ?= lecture-note-2025F

DIR_REVEAL_JS ?= /Users/tristartom/workspace/Courses/slides-revealjs/reveal.js

html: $(FILE).md
	echo "$(DIR_REVEAL_JS)"
	pandoc -t revealjs \
	  --standalone \
	  --variable theme=white \
	  --variable revealjs-url=$(DIR_REVEAL_JS) \
	  --css custom.css \
	  -o "$(FILE).html" "$(FILE).md"
	@######begin: add base dir to html, so no dep. on reveal.js dir
	cp "$(FILE).html" tmp.html
	cp preample.html "$(FILE).html"
	cat tmp.html >> "$(FILE).html"
	rm tmp.html
	@######end
	open -a "Google Chrome" "$(FILE).html"

# Themes: black, league, night, simple, solarized, beige, blood, moon, serif, sky, white

pdf: html
	wkhtmltopdf --enable-local-file-access "$(FILE).html" "$(FILE).pdf"

txt: $(FILE).md
	pandoc --standalone --from markdown+smart --to plain -o "$(FILE).txt" "$(FILE).md"
	vim $(FILE).txt

handout-h: $(FILE).md
	pandoc --standalone --from markdown --to html -o "$(FILE)-h.html" "$(FILE).md"

h: handout-h
	wkhtmltopdf "$(FILE)-h.html" "$(FILE)-h.pdf"
	open "$(FILE)-h.pdf"

clean:
	rm -f *.html *.pdf *.docx *.txt

