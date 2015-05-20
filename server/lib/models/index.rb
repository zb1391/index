class Index
  attr_accessor :client_server, :signed_in_users

  def initialize
    self.signed_in_users = {}
    self.client_server = ClientServer.new(self.signed_in_users)
  end
end
