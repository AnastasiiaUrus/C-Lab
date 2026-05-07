all:
	g++ main.cpp ArticleProcessor.cpp -o article_app
clean:
	rm article_app