class ClientServerThread
  attr_reader :state, :client
  
  def initialize(client)
    @state = states[:verify]
  end

  private

  def states
    @states ||= {
      verify: "VerifyCredentials"
    }
  end
end
