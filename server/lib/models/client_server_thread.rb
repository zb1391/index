class ClientServerThread
  attr_reader :state, :client, :message
  
  def initialize(client)
    @client = client
    @state = states[:verify]
  end

  def parse_message
    msg = @client.gets
    @message = eval(msg)
  end

  def get_client_data
    loop do
      parse_message
      case @state
        when states[:verify]
          # do stuff
        else
          return
      end
    end
  end
  private

  def states
    @states ||= {
      verify: "VerifyCredentials"
    }
  end
end
