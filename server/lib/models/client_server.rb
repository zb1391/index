class ClientServer
	attr_accessor :windows_server, :is_listening

	def initialize
		self.windows_server = TCPServer.open(ENV["WINDOWS_PORT"].to_i)
		Thread.start{listen_for_clients}
	end

	def listen_for_clients
		self.is_listening = true
		loop do
			Thread.start(windows_server.accept) do |client|
				puts 'CONNECTED'.green
				client.close
			end
		end
		self.is_listening = false
	end
end