import pika
connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

def callback(ch, method, properties, body):
    print(" [x] Received", body)
    findindb(body)

def findindb(body):
	print("we will find", body, "in database here")

channel.queue_declare(queue='members')
channel.basic_consume(queue='members', auto_ack=True, on_message_callback=callback)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()